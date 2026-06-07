using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using OFOS_WebAPI.DTOs;
using OFOS_WebAPI.Models;
using System.Security.Cryptography;
using Microsoft.AspNetCore.Cors;
using Microsoft.IdentityModel.Tokens;
using System.IdentityModel.Tokens.Jwt;
using System.Security.Claims;
using System.Text;
using Microsoft.EntityFrameworkCore;
using System.Linq.Expressions;

namespace OFOS_WebAPI.Controllers
{
    [ApiController]
    [Route("user")]
    public class AuthController : ControllerBase
    {
        private readonly AppDbContext _context;
        private readonly IConfiguration _configuration;

        public AuthController(AppDbContext context, IConfiguration configuration)
        {
            _context = context;
            _configuration = configuration;
        }

        [AllowAnonymous]
        [HttpPost("signup")]

        public async Task<IActionResult> Signup(RegisterDto dto)
        {
            try
            {
                string hashedPassword = BCrypt.Net.BCrypt.HashPassword(dto.Password);
                var user = new User
                {
                    Name = dto.Name,
                    Email = dto.Email,
                    Password = hashedPassword,
                    Mobile = dto.Mobile
                };

                _context.Users.Add(user);
                await _context.SaveChangesAsync();
                return Ok(ResultHelper.Success(user));
            }
            catch (Exception ex)
            {
                return BadRequest(ResultHelper.Error<string>(ex.Message));
            }
        }

        [AllowAnonymous]
        [HttpPost("signin")]
        public async Task<IActionResult> Signin(LoginDto dto)
        {
            try
            {
                var dbUser = await _context.Users.FirstOrDefaultAsync(x =>
                    x.Email == dto.Email);

                if (dbUser == null)
                {
                    return BadRequest(ResultHelper.Error
                        <string>("Invalid Email"));}

                    bool isPasswordCorrect = BCrypt.Net.BCrypt.Verify(
                          dto.Password, dbUser.Password);

                    if (!isPasswordCorrect)
                    {
                        return BadRequest(ResultHelper.Error<string>(
                                   "Invalid Password"));
                    }

                    //var token = GenerateToken(dbUser);
                    var response = new
                    {
                        //Token = token,
                        Name = dbUser.Name
                    };
                

                    return Ok(ResultHelper.Success(response));
                
            }

            catch (Exception ex)
            {
                return BadRequest(ResultHelper.Error<string>(ex.Message));
            }
        }
    }
}
            
            
           

using OFOS_WebAPI.DTOs;
using OFOS_WebAPI.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Cors;
using Microsoft.EntityFrameworkCore;
using Microsoft.AspNetCore.Http.HttpResults;
using System.Linq.Expressions;

namespace OFOS_WebAPI.Controllers
{
    [Route("food")]
    [ApiController]

    public class FoodController : ControllerBase
    {
        private readonly AppDbContext _context;

        private readonly IWebHostEnvironment _environment;

        public FoodController(AppDbContext context, IWebHostEnvironment environment)
        {
            _context = context;
            _environment = environment;
        }
        [HttpGet("menu")]

        public async Task<IActionResult> Menu()
        {
            try
            {
                var foods = await _context.Foods.ToListAsync();
                return Ok(ResultHelper.Success(foods));
            }
            catch (Exception ex)
            {
                return BadRequest(ResultHelper.Error<string>(ex.Message));
            }
        }
        [HttpPost]
        public async Task<IActionResult> AddFood(
            [FromForm] FoodCreateDto dto)
        {
            try
            {
                string filename = "";

                if (dto.Image != null)
                {
                    filename = dto.Image.FileName;
                    string folderPath = Path.Combine(_environment.WebRootPath, "foodImages");

                    if (!Directory.Exists(folderPath))
                        Directory.CreateDirectory(folderPath);

                    string filePath = Path.Combine(folderPath, filename);

                    using var stream = new FileStream(filePath, FileMode.Create);

                    await dto.Image.CopyToAsync(stream);
                }

                var food = new Food
                {
                    Name = dto.Name,
                    Price = dto.Price,
                    Description = dto.Description,
                    Image = filename
                };

                _context.Foods.Add(food);

                await _context.SaveChangesAsync();

                return Ok(ResultHelper.Success(food));
            }
            catch (Exception ex)
            {
                return BadRequest(ResultHelper.Error<string>(ex.Message));
            }
           
        }
    }
}


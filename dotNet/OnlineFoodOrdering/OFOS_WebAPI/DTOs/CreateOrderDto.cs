namespace OFOS_WebAPI.DTOs
{
    public class CreateOrderDto
    {
        public decimal TotalAmount { get; set; }
        public List<CartItemDto> CartItem { get; set; }
    }
}

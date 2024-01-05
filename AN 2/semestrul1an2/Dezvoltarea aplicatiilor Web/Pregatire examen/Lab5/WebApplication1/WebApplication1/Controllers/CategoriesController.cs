using Microsoft.AspNetCore.Mvc;
using WebApplication1.Models;

namespace WebApplication1.Controllers
{
    public class CategoriesController : Controller
    {
        private readonly AppDbContext db;

        public CategoriesController(AppDbContext context)
        {
            db = context;
        }

        public IActionResult Index()
        {
            return View();
        }
    }
}

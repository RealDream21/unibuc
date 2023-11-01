using Laborator_5.Models;
using Microsoft.AspNetCore.Mvc;

namespace Laborator_5.Controllers
{
    public class CategoriesController : Controller
    {
        private readonly AppDbContext db;

        public  CategoriesController(AppDbContext context)
        {
            db = context;
        }
        public IActionResult Index()
        {
            var categories = from Category in db.Categories
                             select Category;

            ViewBag.Categories = categories;

            return View();
        }
    }
}

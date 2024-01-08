using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
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

        public IActionResult Delete(int id)
        {
            Category category = db.Categories.Include("Articles").Where(c => c.Id == id).First();//sterge in cascada
            db.Categories.Remove(category);
            db.SaveChanges();
            return RedirectToAction("Index");
        }


    }
}

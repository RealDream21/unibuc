using Microsoft.AspNetCore.Mvc;
//nu are acces la Article[] => trebuie sa l punem noi
using Laborator4.Models;

namespace Laborator4.Controllers
{
    public class ArticlesController : Controller
    {
        [NonAction]
        public Article[] GetArticles()
        {
            // Se instantiaza un array de articole
            Article[] articles = new Article[3];
            // Se creeaza articolele
            for (int i = 0; i < 3; i++)
            {
                Article article = new Article();
                article.Id = i;
                article.Title = "Articol " + (i + 1).ToString();
                article.Content = "Continut articol " + (i + 1).ToString();
                article.Date = DateTime.Now;
                // Se adauga articolul in array
                articles[i] = article;
            }
            return articles;

        }

        //[HttpGet] - se executa GET implicit
        //[ActionName("listare")] NU MERGE?????
        public IActionResult Index()
        {
            Article[] articles = GetArticles();

            //ViewBag.NumeVariabila !!! NU ESTE O METODA ANUME SAU CEVA STANDARD !!!
            //ViewBag primeste un nume pe care l dam noi
            //Se adauga array-ul de articole in View
            //ViewBag => ia array din articles si le duce in View
            ViewBag.Articles = articles;

            return View(); //returneaza view-ul cu acelasi nume ca si metoda
        }

        public IActionResult Show(int? id)
        {
            Article[] articles = GetArticles();
            try
            {
                ViewBag.Article = articles[(int)id];
                return View();
            }
            catch (Exception e)
            {
                ViewBag.ErrorMessage = e.Message;
                return View("Error");
            }
        }

        [HttpGet]//GET: Afisarea formularului de creare a unui articol
        public IActionResult New()
        {
            return View();
        }

        [HttpGet]
        public IActionResult Edit(int? id)
        {
            Article[] articles = GetArticles();
            try
            {
                ViewBag.Article = articles[(int)id];
                return View();
            }
            catch(Exception e)
            {
                ViewBag.Exception = e.Message;
                return View("Error");
            }
        }

        [HttpPost]
        public IActionResult Edit(Article article)
        {
            return View("EditMethod");
        }

        [HttpPost]
        public IActionResult Delete(int? id)
        {
            return Content("Articolul a fost sters din baza de date");
        }

    }
}

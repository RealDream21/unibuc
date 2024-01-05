using Microsoft.AspNetCore.Mvc;
using WebApplication1.Models;

namespace WebApplication1.Controllers
{
    public class StudentsController : Controller
    {
        private readonly AppDbContext db;
        public StudentsController(AppDbContext context)
        {
            db = context;
        }


        public IActionResult Index()
        {
            var students = from student in db.Students
                           orderby student.Name
                           select student;
            ViewBag.Students = students;
            return View();
        }

        public IActionResult Show(int? id)
        {
            Student student = db.Students.Find(id);
            ViewBag.Student = student;

            return View();
        }

        public IActionResult New()
        {
            return View();
        }

        [HttpPost]
        public IActionResult New(Student student)
        {
            try
            {
                db.Students.Add(student);
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            catch (Exception)
            {
                return View();
            }
        }

        public IActionResult Edit(int id)
        {
            Student student = db.Students.Find(id);
            ViewBag.Student = student;
            return View();
        }

        [HttpPost]
        public IActionResult Edit(int id, Student requestStudent)
        {
            Student student = db.Students.Find(id);
            try
            {
                student.Name = requestStudent.Name;
                student.Email = requestStudent.Email;
                student.CNP = requestStudent.CNP;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            catch(Exception)
            {
                return RedirectToAction("Edit", student.StudentId);
            }
        }

        [HttpPost]
        public IActionResult Delete(int id)
        {
            Student student = db.Students.Find(id);
            db.Students.Remove(student);
            db.SaveChanges();
            return RedirectToAction("Index");
        }



    }
}

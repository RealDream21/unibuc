using Microsoft.AspNetCore.Mvc.Rendering;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace WebApplication1.Models
{
    public class Article
    {
        [Key]
        public int Id { get; set; }

        public string Title { get; set; }
        public string Content {  get; set; }

        public DateTime Date {  get; set; }

        public int? CategoryId {  get; set; }
        public Category Category { get; set; }

        [NotMapped]
        public IEnumerable<SelectListItem> Categ {  get; set; }



    }
}

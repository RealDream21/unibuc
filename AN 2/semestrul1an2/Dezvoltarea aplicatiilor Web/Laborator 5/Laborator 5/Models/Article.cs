using System.ComponentModel.DataAnnotations;

namespace Laborator_5.Models
{
    public class Article
    {
        [Key]
        public int Id { get; set; }
        public string CategoryName { get; set; }
    }
}

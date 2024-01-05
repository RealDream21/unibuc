using System.ComponentModel.DataAnnotations;

namespace WebApplication1.Models
{
    public class Student
    {
        [Key]
        public int StudentId { get; set; }
        public string Name {get; set;}
        public string Email { get; set;}
        public string CNP { get; set;}
    }
}

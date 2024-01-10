using Microsoft.EntityFrameworkCore;

namespace Laborator5.Models
{
    public class AppDBContext : DbContext
    {
        public AppDBContext(DbContextOptions<AppDBContext> options) : base(options)
        {
        }

    /*
      public AppDBContext() : base()
      {
      }

      protected override void OnConfiguring(DbContextOptionsBuilder options)
      {
        options.UseSqlServer(@"Server=(localdb)\mssqllocaldb;Database=aspnet-53bc9b9d-9d6a-45d4-8429-2a2761773502;Trusted_Connection=True;MultipleActiveResultSets=true");
      }
    */

        public DbSet<Article> Articles { get; set; }
        public DbSet<Category> Categories { get; set; }

    }
}

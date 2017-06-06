using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using BlogWebApi.Models;
using System.Data.SqlClient; 

namespace BlogWebApi.Controllers
{
    public class BlogController : ApiController
    {
        List<Blog> blogs = new List<Blog> {};

        [HttpGet]
        [ActionName("blogs")]
        public object GetBlog()
        {
            var bls = this.queryBlogs();
            return new {
                blogList = blogs
            };
        }

        public List<Blog> queryBlogs()
        {

            using (var conn = new SqlConnection("data source=localhost;database=MIEngineering;trusted_connection=true"))
            {
                try
                {
                    conn.Open();
                    var command = new SqlCommand("dbo.GetBlogsAndTags", conn);
                    command.CommandType = System.Data.CommandType.StoredProcedure;

                    using (var reader = command.ExecuteReader())
                    {
                        while (reader.Read())
                        {
                            var Id = reader.GetInt32(0);
                            var Content = reader.GetString(1);
                            var Author = reader.GetString(2);
                            var BlogType = reader.GetString(3);
                            var Tags = Blog.buildTags(reader.GetString(4));

                            blogs.Add(new Blog { id = Id , author = Author, content = Content, blogType = BlogType, tags = Tags });
                        }

                        return blogs; 

                    }

                }
                catch (SqlException ex)
                {
                    return blogs;
                }
                finally
                {
                    conn.Close();
                }
            }
        }

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using BlogWebApi.Models;

namespace BlogWebApi.Controllers
{
    public class BlogController : ApiController
    {
        Blog[] blogs = new Blog[] {
            new Blog { Id = 1, Author = "Chris Workman", Content = "Hello World", Type = "FrontEnd" }
        };

        [HttpGet]
        [ActionName("blogs")]
        public object GetBlog()
        {
            return new
            {
                blogList = blogs
            };
        }
    }
}

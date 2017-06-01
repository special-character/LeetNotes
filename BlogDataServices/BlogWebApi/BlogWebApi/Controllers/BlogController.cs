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
            new Blog { id = 1, author = "Chris Workman", content = "Hello World", blogType = "FrontEnd" }
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

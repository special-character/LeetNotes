external markdown : ReactRe.reactClass = "Markdown" [@@bs.module "react-showdown"];
  /* this is the call that takes in Reason data and converts it to JS data. Make sure you get the conversion right! JS won't warn you of type errors... */
  let createElement 
    markup::(markup: string) =>
    ReactRe.wrapPropsShamelessly
     markdown 
      {
        "markup": markup
      };

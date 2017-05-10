
  external col : ReactRe.reactClass = "Col" [@@bs.module "react-bootstrap"];
  /* this is the call that takes in Reason data and converts it to JS data. Make sure you get the conversion right! JS won't warn you of type errors... */
  let createElement 
  ::md =>
  ReactRe.wrapPropsShamelessly
   col 
   {
    "md": md
   }
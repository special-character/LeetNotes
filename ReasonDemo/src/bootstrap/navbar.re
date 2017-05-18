
  external navbar : ReactRe.reactClass = "Navbar" [@@bs.module "react-bootstrap"];
  /* this is the call that takes in Reason data and converts it to JS data. Make sure you get the conversion right! JS won't warn you of type errors... */

  /* hi */
  let createElement =
  ReactRe.wrapPropsShamelessly
   navbar  
    (Js.Obj.empty ())
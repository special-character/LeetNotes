
  external nav: ReactRe.reactClass = "Nav" [@@bs.module "react-bootstrap"];
  /* this is the call that takes in Reason data and converts it to JS data. Make sure you get the conversion right! JS won't warn you of type errors... */

  let createElement =
  ReactRe.wrapPropsShamelessly
   nav 
    (Js.Obj.empty ())
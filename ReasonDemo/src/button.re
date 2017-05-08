include ReactRe; 

external buttonRe : ReactRe.reactClass = "react-bootstrap/lib/Button.js" [@@bs.module];

/* this is the call that takes in Reason data and converts it to JS data. Make sure you get the conversion right! JS won't warn you of type errors... */
let createElement =
  ReactRe.wrapPropsShamelessly
    buttonRe 
    (Js.Obj.empty ())
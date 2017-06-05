external label : ReactRe.reactClass = "Label" [@@bs.module "react-bootstrap"];
  /* this is the call that takes in Reason data and converts it to JS data. Make sure you get the conversion right! JS won't warn you of type errors... */

  /* hi */
  let createElement 
  bsStyle::(bsStyle: string) =>
  ReactRe.wrapPropsShamelessly
   label  
   {
       "bsStyle": bsStyle
   }
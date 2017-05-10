
  external button : ReactRe.reactClass = "Button" [@@bs.module "react-bootstrap"];
  /* this is the call that takes in Reason data and converts it to JS data. Make sure you get the conversion right! JS won't warn you of type errors... */
  let createElement 
    onClick::(onClick: ReactEventRe.Mouse.t => unit) =>
    ReactRe.wrapPropsShamelessly
      button
      {
        "onClick": onClick     
      };


  external navItem : ReactRe.reactClass = "NavItem" [@@bs.module "react-bootstrap"];
  /* this is the call that takes in Reason data and converts it to JS data. Make sure you get the conversion right! JS won't warn you of type errors... */
  let createElement 
    href::(href: string)
    onClick::(onClick: ReactEventRe.Mouse.t => unit)
    eventKey::(eventKey: int) =>
    ReactRe.wrapPropsShamelessly
      navItem
      {
        "href": href, 
        "onClick": onClick, 
        "eventKey": eventKey 
      };

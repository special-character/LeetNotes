open Pervasives;
open ReactRe; 
/* This is like the object declaration part of ReactJS' React.createClass()*/

module Button = {
  
  external button : ReactRe.reactClass = "Button" [@@bs.module "react-bootstrap"];
  /* this is the call that takes in Reason data and converts it to JS data. Make sure you get the conversion right! JS won't warn you of type errors... */
  let createElement 
    onClick::(onClick: ReactEventRe.Mouse.t => unit) =>
    ReactRe.wrapPropsShamelessly
      button
      {
        "onClick": onClick     
      };
};




module Page = {
  include ReactRe.Component.Stateful;
  type props = {message: string};
  type state = {counter: int};
  let name = "Page";
  let getInitialState _ => {
    counter: 0
  };
  let handleClick {state} _ => {
    Js.log "clicked";
    switch (state.counter) {
    | -1 => None 
    | nonEmptyValue => Some {counter:nonEmptyValue+1}
    };
  };

  let render {state, props, updater} =>
    <div>
    <div> (ReactRe.stringToElement props.message) </div>
    <Button onClick=(updater handleClick)>(ReactRe.stringToElement "Click Me")</Button>
    <div>(ReactRe.stringToElement (Js.String.make state.counter))</div>
     </div>;
};

/* This is the equivalent of React.createClass 
  ReactRe.CreateComponent takes in the Page component and returns a new module containing
  commp and wrapProps
*/
include ReactRe.CreateComponent Page;

/* The actual call that is exposed to consumers, via JSX    */
let createElement ::message => wrapProps {message: message};
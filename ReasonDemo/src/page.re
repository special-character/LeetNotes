open Pervasives;
open ReactRe; 
/* This is like the object declaration part of ReactJS' React.createClass()*/
module Page = {
  include ReactRe.Component.Stateful;
  type props = {message: string};
  type state = {
                  counter: int,
                  textBoxValue: string
               };
  let name = "Page";
  let getInitialState _ => {
    counter: 0,
    textBoxValue: "..."
  };
  let handleClick {state} _ => {
    Js.log "clicked";
    switch (state.counter) {
    | -1 => None 
    | nonEmptyValue => Some {...state, counter:nonEmptyValue+1}
    };
  };

  let handleTextBoxChange {state} event => {
     Js.log state.textBoxValue; 
     Some {...state, 
            textBoxValue:(ReactDOMRe.domElementToObj (ReactEventRe.Keyboard.target event))##value
            };
  };
  
  
  let render {state, props, updater} =>
    <div>
    <div> (ReactRe.stringToElement props.message) </div>
    <Button onClick=(updater handleClick)>(ReactRe.stringToElement "Click Me")</Button>
    <ControlLabel>(ReactRe.stringToElement "Header for Component")</ControlLabel>
    <Row>
      <Col md=4>
    <FormControl value=state.textBoxValue onChange=(updater handleTextBoxChange)/>
      </Col>
      <Col md=8>
      </Col>
    </Row>
    <div>(ReactRe.stringToElement (Js.String.make state.counter))</div>
    <Row>
      <ModalDialog>
      <ModalHeader>
          <ModalTitle>(ReactRe.stringToElement (Js.String.make "Fake Ass Title"))</ModalTitle>
        </ModalHeader>
        <ModalBody>
          (ReactRe.stringToElement (Js.String.make "Ayoooo"))
        </ModalBody>
        <ModalFooter>
        </ModalFooter>
      </ModalDialog>
    </Row>
    </div>;
};

/* This is the equivalent of React.createClass 
  ReactRe.CreateComponent takes in the Page component and returns a new module containing
  commp and wrapProps
*/
include ReactRe.CreateComponent Page;

/* The actual call that is exposed to consumers, via JSX    */
let createElement ::message => wrapProps {message: message};
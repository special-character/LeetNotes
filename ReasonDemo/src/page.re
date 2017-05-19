open Pervasives;
open ReactRe; 
open Ajax; 
/* This is like the object declaration part of ReactJS' React.createClass()*/
module Page = {
  include ReactRe.Component.Stateful;
  type props = {message: string};
  type state = {
                  counter: string,
                  textBoxValue: string
               };
  let name = "Page";
  let getInitialState _ => {
    counter: "1",
    textBoxValue: "..."
  };


  let sortNumbers = fun nums:string => {

    let data = Js_json.parse {| {"id" : "chris"}|};
    let d = Ajax.ajaxPost "http://localhost:8081/listUsers" data; 

    let result = Js.String.splitByRe (Js.Re.fromString ",") nums
    |> Array.to_list
    |> List.map (fun x => int_of_string x)
    |> List.sort compare
    |> List.map (fun x => string_of_int x)
    |> List.fold_left (fun acc x => acc ^ "," ^ x) "";

    Js.String.substringToEnd 1 result;
  };

  let handleClick {state} _ => {
    Js.log "clicked";
    switch (state.textBoxValue) {
    | "" => None 
    | nonEmptyValue =>  Some {...state, textBoxValue:(sortNumbers nonEmptyValue)};
    };
  };

  let handleTextBoxChange {state} event => {
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
      /*<ModalDialog>
      <ModalHeader>
          <ModalTitle>(ReactRe.stringToElement (Js.String.make "Fake Ass Title"))</ModalTitle>
        </ModalHeader>
        <ModalBody>
          (ReactRe.stringToElement (Js.String.make "Ayoooo"))
        </ModalBody>
        <ModalFooter>
        </ModalFooter>
      </ModalDialog>*/
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
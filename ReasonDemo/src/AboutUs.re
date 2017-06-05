open Pervasives;
open ReactRe;
open Markdown; 

module AboutUs = {
    
    include ReactRe.Component.Stateful;
    type props = unit;
    type state = {
        id : int  
    };
    let name = "AboutUs";


    let getInitialState props => { 
        id : 0 
    };

    
    let render {state, props, updater} => {
    <div>
        <Row>
            (ReactRe.stringToElement "aa") 
        </Row>
    </div>;
    };
};

include ReactRe.CreateComponent AboutUs;

let createElement = wrapProps ();
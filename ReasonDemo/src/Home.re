open Pervasives;
open ReactRe;
open Markdown; 

module Home = {
    
    include ReactRe.Component.Stateful;
    type props = {name: string}; 
    type contentItem = {
        .
        id: string,
        content: string
    };
    type state = {
        contentList : list contentItem  
    };
    let name = "Home";

    let handleData {setState} data => {

        let stateSetter {state} => { 
            let ncl = [data];
            {...state, contentList : ncl}
        };
        setState stateSetter;
        None
    };

    let getInitialState props => { 
        contentList : [] 
    };

    let componentDidMount {state, setState, handler, updater} => {        
        
        updater handleData
        |> Ajax._then (Ajax.ajaxPost "http://localhost:8081/listUsers" );
        None; 
    };
    
    
    let render {state, props, updater} => {

    Js.log state;     

    <div>
        <Navigation name="MedInsight Engineering" pages={["About Us","Blog","Internal Metrics","Jobs"]}/>
        <Row>
            <Col md=2>
            </Col>
                <Col md=8>
                    <Jumbotron>
                        <h2>(ReactRe.stringToElement "Home of MedInsight Engineering")</h2>
                    </Jumbotron>
                </Col>
            <Col md=2>
            </Col>
        </Row>
        <Row>
            <Col md=2>
            </Col>
            <Col md=4>
                <Panel header="Backend" bsStyle="primary">
                </Panel>
            </Col>
            <Col md=4>
                <Panel header="FrontEnd" bsStyle="danger">
                </Panel>
            </Col>
            <Col md=2>
            </Col>
        </Row>
        /*<Markdown markup=text />*/
    </div>;
    };
};

include ReactRe.CreateComponent Home;

let createElement ::name => wrapProps {name: name};
open Pervasives;
open ReactRe;
open Markdown; 

module Home = {
    include ReactRe.Component;
    type props = {name: string}; 
    let name = "Home";

    let handleData = fun data => {
        let p = 8;
        Js.log p;
    };

    let componentDidMount {setState} => {        
        let data = Js_json.parse {| {"id" : "chris"}|};
        /*let d = Ajax.ajaxPost "http://localhost:8081/listUsers" data;  */
        let dataHandler = Ajax.bnd handleData "hello";
        let e = Ajax.then_ (Ajax.ajaxPost "http://localhost:8081/listUsers" data) (Ajax.bnd handleData "hello");
        Js.log e; 
        None; 
    };

    let render {state, props, updater} =>
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
        <Markdown markup="#hello, markdown!" />
    </div>;
};

include ReactRe.CreateComponent Home;

let createElement ::name => wrapProps {name: name};
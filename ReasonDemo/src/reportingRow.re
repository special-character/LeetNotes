/*open Pervasives;
open ReactRe;

module ReportingComponent = {
    include ReactRe.Component;
    type props = {name: string}; 
    let name = "Home";

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
    </div>;
};

include ReactRe.CreateComponent Home;

let createElement ::name => wrapProps {name: name};*/
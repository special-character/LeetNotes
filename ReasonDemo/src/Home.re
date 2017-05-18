open Pervasives;
open ReactRe;

module Home = {
    include ReactRe.Component;
    type props = {name: string}; 
    let name = "Page";
    

    let render {state, props, updater} =>
    <div>
        <Navbar>
            <NavbarHeader>
            <NavbarBrand>
                <a href="#">(ReactRe.stringToElement "MedInsight Engineering")</a>
            </NavbarBrand>
            </NavbarHeader>
            <Nav>
                <NavItem eventKey={1} href="#">(ReactRe.stringToElement "Blog")</NavItem>
                <NavItem eventKey={2} href="#">(ReactRe.stringToElement "About Us")</NavItem>
                <NavItem eventKey={3} href="#">(ReactRe.stringToElement "Jobs")</NavItem>
            </Nav>
        </Navbar>
    </div>;
};

include ReactRe.CreateComponent Home;

let createElement ::name => wrapProps {name: name};
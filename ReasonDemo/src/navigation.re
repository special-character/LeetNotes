open Pervasives;
open ReactRe; 
open ReactEventRe;

module Navigation = {
    include ReactRe.Component;
    type props = {
                   pages: list string, 
                   name: string,
                   pageHandler: unit => unit
                 };
    let name = "Navigation";

    let render {state, props, handler} => {

        let { pages, name, pageHandler } = props;
        let navItems = pages 
                    |> List.map (fun name => 
                    <NavItem eventKey={1} onClick=(fun name => pageHandler() ) href="#">(ReactRe.stringToElement name)</NavItem>
                    );
    
        <div>
            <Navbar inverse=true>
                <NavbarHeader>
                <NavbarBrand>
                    <a href="#">(ReactRe.stringToElement name)</a>
                </NavbarBrand>
                </NavbarHeader>
                <Nav>
                    (ReactRe.listToElement navItems)
                </Nav>
            </Navbar>
        </div>
    };
};

include ReactRe.CreateComponent Navigation;

let createElement ::pages ::name ::pageHandler => wrapProps {pages: pages, name: name, pageHandler: pageHandler};

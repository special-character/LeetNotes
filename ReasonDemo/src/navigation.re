open Pervasives;
open ReactRe; 

module Navigation = {
    include ReactRe.Component;
    type props = {
                   pages: list string, 
                   name: string,
                 };
    let name = "Navigation";

    let render {state, props} => {

        let { pages, name } = props;
        let navItems = pages 
                    |> List.map (fun name => <NavItem eventKey={1} href="#">(ReactRe.stringToElement name)</NavItem>);
    
        <div>
            <Navbar>
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

let createElement ::pages ::name => wrapProps {pages: pages, name: name};

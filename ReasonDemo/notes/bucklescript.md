##Bucklescript

bs.val = used to bind to a js value, can be a function or plain value
```js
(* Abstract type for the DOM *)
external dom : dom = "document" [@@bs.val]
```

bs.new = bind to a javascript constructor

```js
external create_person : unit -> t = "Person" [@@bs.new]
let chris = create_person ()

======>JS OUTPUT 
var chris = new Person()
```
    
bs.modules = bind to a js module 

```js
external add : int -> int -> int = "add" [@@bs.module "x"]
let f = add 2 3

======>JS OUTPUT
var f = X.add(3, 4);

```
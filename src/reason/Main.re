module R = Belt.Result;

/* PORTS */
type ports = {
  .
  "infoForReason": Elm.portFromElm(string),
  "infoForElm": Elm.portToElm(string),
};

/* ELM PROGRAM */
[@bs.module]
external elmProgram : Elm.elmProgramWithPorts(ports) =
  "../elm/Other/Main.elm";

let instance =
  Elm.mount(
    ~flags={"title": "Buttons (title set in Reason via flags)"},
    ~moduleName="Other.Main",
    elmProgram,
  );

switch (instance) {
| R.Ok(i) =>
  let infoForReason = i##ports##infoForReason;
  let infoForElm = i##ports##infoForElm;
  infoForReason##subscribe(info => infoForElm##send("You pressed " ++ info));
| R.Error(message) => Js.log(message)
};

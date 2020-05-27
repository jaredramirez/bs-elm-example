module R = Belt.Result;

type ports = {
  infoForReason: Elm.elmToReasonPort(string),
  infoForElm: Elm.reasonToElmPort(string),
};

[@bs.module]
external elmProgram: Elm.elmProgramWithPorts(ports) = "../elm/Other/Main.elm";

type flags = {title: string};

let resultRuntime =
  Elm.mount(
    ~flags={title: "Text below buttons set in Reason via flags"},
    ~moduleName="Other.Main",
    elmProgram,
  );

switch (resultRuntime) {
| R.Ok(runtime) =>
  runtime.ports.infoForReason.subscribe(info =>
    runtime.ports.infoForElm.send("You pressed " ++ info)
  )
| R.Error(message) => Js.log(message)
};

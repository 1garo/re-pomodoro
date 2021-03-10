open State;

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  React.useEffect0(() => {
    let timer = Js.Global.setInterval(() => dispatch(Tick), 1000);
    Some(() => Js.Global.clearInterval(timer));
  });

  <div> 
    <Timer seconds={state.seconds}> </Timer>
    <button onClick={_ => dispatch(Stop)}> {React.string("Stop")} </button>
    <button onClick={_ => dispatch(Start)}> {React.string("Start")} </button>
    <button onClick={_ => dispatch(Reset)}> {React.string("Reset")} </button>

    <EditTime
    phase="Work"
    value={state.workTime} 
    onChange={e => dispatch(SetTime(Work, e))}
    />

    <EditTime
    phase="Break"
    value={state.playTime} 
    onChange={e => dispatch(SetTime(Play, e))}
    />

  </div>
}


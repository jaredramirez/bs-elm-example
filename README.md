## Reason-Elm Example

### Running the example
* Clone this repository `git clone https://github.com/jaredramirez/reason-elm-example.git`
* Go in the directory `cd reason-elm-example`
* Install the dependencies with `yarn install` or `npm install`
* Launch the dev server with `yarn webpack:serve` or `npm run webpack:serve`
* Navigate to [`localhost:8080`](http://localhost:8080)
* Open the code and poke around!

### Other things
* This example is pretty simple, but demonstrates mounting an Elm app in Reason, passing flags on the app instantiation, and interacting with ports. If there's other example you want (like an example of ports following the actor model?), let me know!
* There's some pretty cool usage of webpack in this example, because you can import the Elm application directly in Reason. Checkout the [`webpack config`](webpack.config.js) for more details.

'use strict';

const path = require('path');
const webpack = require('webpack');
const HtmlWebpackPlugin = require('html-webpack-plugin');

const resolvePath = relativePath => path.resolve(__dirname, relativePath);

module.exports = {
  devtool: 'cheap-module-source-map',

  entry: resolvePath('src/reason/Main.bs.js'),

  output: {
    path: resolvePath('lib'),
    filename: 'bundle.js',
  },

  module: {
    rules: [
      {test: /\.(js|jsx)$/, use: require.resolve('babel-loader')},
      {
        test: /\.elm$/,
        exclude: [/elm-stuff/, /node_modules/],
        use: {
          loader: require.resolve('elm-webpack-loader'),
          options: {
            cwd: resolvePath('.'),
            forceWatch: true,
            debug: true,
          },
        },
      },
    ],
  },

  resolve: {
    extensions: ['.js', '.jsx', '.elm'],
  },

  plugins: [
    new HtmlWebpackPlugin({
      inject: true,
      template: resolvePath('public/index.html'),
    }),
  ],
};

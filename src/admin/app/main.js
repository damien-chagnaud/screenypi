"use strict";

require.config({
    baseUrl: 'app',
    paths: {
        'jquery': '../libs/jquery/jquery',
        'backbone': '../libs/backbone/backbone',
        'underscore': '../libs/underscore/underscore',
		'bootstrap': '../libs/boostrap/js/bootstrap.js',
		'text': '../libs/requirejs/text',
		'i18n': '../libs/requirejs/i18n',
		'json': '../libs/requirejs/json',
        'app': '.',
		'tpl': '../tpl',
		'nls':  '../nls'
		
		
    },

	config: {
        i18n: {
            locale: 'fr-fr'
        }
    },
	
    shim: {
		underscore: {
			exports: "_"
		},
		
		backbone: {
			deps: ['underscore', 'jquery'],
			exports: 'Backbone'
		}
	}
});

require(['jquery', 'backbone', 'app/router'], function ($, Backbone, Router) {
    var router = new Router();
	
	
    Backbone.history.start();
});
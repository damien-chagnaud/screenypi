define(function(require) {

    "use strict";

    var $                   = require('jquery'),
		_                   = require('underscore'),
		Backbone            = require('backbone'),
		tpl                	= require('text!tpl/bluetooth.html'),
		tplCss				= require('text!tpl/bluetooth.css'),
		//usersMdls			= require('models/users'),
		bluetooth 				= require('i18n!nls/bluetooth'),
		
		template 			= _.template(tpl);
		
	
	return Backbone.View.extend({
		events: {
			"click #add_users": "addUser",
			"click #refresh_users": "refreshUser",
		},
  
		render: function () {
			
			$('head').append('<style type="text/css" id="usersStyle">'+tplCss+'</style>');
			
			this.$el.html(template({bluetooth}));

			return this;
		},
		
		addUser: function () {
			console.log("Ajout d'utilisatreurs");
			
		},
		
		refreshUser: function () {
			console.log("Rafraichir utilkisatreurs");
			
		}
		
	});

});
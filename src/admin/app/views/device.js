define(function(require) {

    "use strict";

    var $                   = require('jquery'),
		_                   = require('underscore'),
		Backbone            = require('backbone'),
		tpl                	= require('text!tpl/device.html'),
		tplCss				= require('text!tpl/device.css'),
		//usersMdls			= require('models/users'),
		device 				= require('i18n!nls/device'),
		
		template 			= _.template(tpl);
		
	
	return Backbone.View.extend({
		events: {
			"click #add_users": "addUser",
			"click #refresh_users": "refreshUser",
		},
  
		render: function () {
			
			$('head').append('<style type="text/css" id="usersStyle">'+tplCss+'</style>');
			
			this.$el.html(template({device}));

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
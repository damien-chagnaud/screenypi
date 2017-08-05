define(function (require) {

    "use strict";

    var $                       = require('jquery'),
        _                       = require('underscore'),
        Backbone                = require('backbone'),
        SidebarItemView    		= require('app/views/sidebarItem');
		
		
		return Backbone.View.extend({

        initialize: function () {
            this.collection.on("reset", this.render, this);
            this.collection.on("add", this.render, this);
        },

        render: function () {
            this.$el.empty();
			
            _.each(this.collection.models, function (module) {
                this.$el.append(new SidebarItemView({model: module}).render().el);
            }, this);
            return this;
        }
    });

});
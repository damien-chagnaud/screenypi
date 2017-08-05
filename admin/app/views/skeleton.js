define(function (require) {

    "use strict";

    var $                   = require('jquery'),
        _                   = require('underscore'),
        Backbone            = require('backbone'),
		SideBarView    		= require('app/views/sidebar'),
        modulesMdls         = require('app/models/modules'),
        tpl                 = require('text!tpl/skeleton.html'),

        template = _.template(tpl),
        $menuItems;

    return Backbone.View.extend({

        initialize: function () {
            this.moduleList = new modulesMdls.ModuleCollection();
        },

        render: function () {
            this.$el.html(template());

            var sideBarView = new SideBarView({collection: this.moduleList, el: $(".sidebarMenu", this.el)});
            sideBarView.render();
			this.moduleList.fetch();
            $menuItems = $('#sidebar', this.el);
			
            return this;
        }/*,

        events: {
            "keyup .search-query": "search",
            "keypress .search-query": "onkeypress"
        },

        search: function (event) {
            var key = $('#searchText').val();
            this.employeeList.fetch({reset: true, data: {name: key}, success: function () {
                setTimeout(function () {
                    $('.dropdown').addClass('open');
                });
            }});
        },

        onkeypress: function (event) {
            if (event.keyCode === 13) { // enter key pressed
                event.preventDefault();
            }
        },

        selectMenuItem: function (menuItem) {
            $menuItems.removeClass('active');
            if (menuItem) {
                $('.' + menuItem).addClass('active');
            }
        }*/

    });

});
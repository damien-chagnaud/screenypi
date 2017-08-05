define(function (require) {
	
    "use strict";

    var $                   = require('jquery'),
        Backbone            = require('backbone'),
		
		User = Backbone.Model.extend({
			
			sync: function (method, model, options) {
				if (method === "read") {
					findByName(parseInt(this.name)).done(function (data) {
						options.success(data);
					});
				}
			}
			
		}),

		UserCollection = Backbone.Collection.extend({

			model: User,

			sync: function (method, model, options) {
				if (method === "read") {
					options.success(moduleList);
				}
			}

		});


    return {
        User: User,
        UserCollection: UserCollection
    };

});
define(function (require) {
	
	
    "use strict";

    var $                   = require('jquery'),
        Backbone            = require('backbone'),
		moduleList			= require('json!app/data/modules.json'),
		
		
		findByName = function (name) {
            var deferred = $.Deferred(),
                module = null,
                l = moduleList.length,
                i;
            for (i = 0; i < l; i = i + 1) {
                if (moduleList[i].name === name) {
                    module = moduleList[i];
                    break;
                }
            }
            deferred.resolve(module);
            return deferred.promise();
        },

		moduleGetRoute = function(mode){
			var moduleRoute = {},
				l = moduleList.length,
				i;
				
			for (i = 0; i < l; i = i + 1) {
				moduleRoute[moduleList[i].route] = (mode.length>0)? mode:moduleList[i].view;
			}
			
			return moduleRoute;
		},
		
		moduleGetBulk = function(){
			return moduleList;
		},
		
		
		Module = Backbone.Model.extend({
			
			sync: function (method, model, options) {
				if (method === "read") {
					findByName(parseInt(this.name)).done(function (data) {
						options.success(data);
					});
				}
			}
			
		}),

		ModuleCollection = Backbone.Collection.extend({

			model: Module,

			sync: function (method, model, options) {
				if (method === "read") {
					options.success(moduleList);
				}
			}

		});


    return {
        Module: Module,
        ModuleCollection: ModuleCollection,
		ModuleGetRoute: moduleGetRoute,
		ModuleGetBulk: moduleGetBulk
    };

});
define(function (require) {

    "use strict";

    var $           	= require('jquery'),
        Backbone    	= require('backbone'),

		SkelView    	= require('app/views/skeleton'),
        dashView    	= require('app/views/dashboard'),
		usersView 		= require('app/views/users'),
		wifiView 		= require('app/views/wifi'),
		bluetoothView 	= require('app/views/bluetooth'),
		sambaView 		= require('app/views/samba'),
		remoteView 		= require('app/views/remote'),
		deviceView 		= require('app/views/device'),

        $body = $('body'),
        
		skelView = new SkelView({el: $body}).render(),
        dashView = new dashView({el: $("#main")}),
		usersView = new usersView({el: $("#main")});
		wifiView = new wifiView({el: $("#main")});
		bluetoothView = new bluetoothView({el: $("#main")});
		sambaView = new sambaView({el: $("#main")});
		remoteView = new remoteView({el: $("#main")});
		deviceView = new deviceView({el: $("#main")});

	
    return Backbone.Router.extend({
		
		
		routes: {
			":item": "routeView",
			"": "routeView"
		},

		
        routeView: function(item){
			
			console.log(item);
			
			switch(item){
				case "users":
					usersView.render();
					break;
				case "wifi":
					wifiView.render();
					break;
				case "bluetooth":
					bluetoothView.render();
					break;
				case "samba":
					sambaView.render();
					break;
				case "remote":
					remoteView.render();
					break;
				case "device":
					deviceView.render();
					break;
				default:
					dashView.render();
			}
			
			


            //SkelView.selectMenuItem('home-menu');
        }

        

    });
	

});
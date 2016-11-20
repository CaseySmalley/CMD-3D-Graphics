var vec = new function() {
	
	this.createVector = function(list) {
		if (!list) {
			return ([
				0.0,0.0,0.0
			]);
		} else {
			return (list);
		}
	}
	
	this.set = function(v,x,y,z) {
		v[0] = x;
		v[1] = y;
		v[2] = z;
	}
	
	this.add = function(v1,v2) {
		v1[0] += v2[0];
		v1[1] += v2[1];
		v1[2] += v2[2];
	}
	
	this.sub = function(v1,v2) {
		v1[0] -= v2[0];
		v1[1] -= v2[1];
		v1[2] -= v2[2];
	}
	
	this.mul = function(v1,v2) {
		v1[0] *= v2[0];
		v1[1] *= v2[1];
		v1[2] *= v2[2];
	}
	
	this.div = function(v1,v2) {
		v1[0] /= v2[0];
		v1[1] /= v2[1];
		v1[2] /= v2[2];
	}
	
	this.length = function(v) {
		return Math.sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
	}
	
}

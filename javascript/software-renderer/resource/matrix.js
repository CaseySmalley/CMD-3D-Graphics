"use strict";

var mat = new function() {
	
	var temp = null;
	var tempVector = null;
	
	this.init = function() {
		temp = this.createMatrix();
		tempVector = this.createMatrix();
	}
	
	this.createMatrix = function(list) {
		if (!list) {
			return ([
				1.0,0.0,0.0,0.0,
				0.0,1.0,0.0,0.0,
				0.0,0.0,1.0,0.0,
				0.0,0.0,0.0,1.0
			]);
		} else {
			return (list);
		}
	}
	
	this.setLocalX = function(m,x,y,z) {
		m[0] = x;
		m[1] = y;
		m[2] = z;
	}
	
	this.setLocalY = function(m,x,y,z) {
		m[4] = x;
		m[5] = y;
		m[6] = z;
	}
	
	this.setLocalZ = function(m,x,y,z) {
		m[8] = x;
		m[9] = y;
		m[10] = z;
	}
	
	this.setPosition = function(m,x,y,z) {
		m[12] = x;
		m[13] = y;
		m[14] = z;
	}
	
	this.rotateX = function(m,a) {
		this.identity(m);
		m[5] = Math.cos(a);
		m[6] = -Math.sin(a);
		m[9] = Math.sin(a);
		m[10] = Math.cos(a);
	}
	
	this.rotateY = function(m,a) {
		this.identity(m);
		m[0] = Math.cos(a);
		m[2] = Math.sin(a);
		m[8] = -Math.sin(a);
		m[10] = Math.cos(a);
	}
	
	this.rotateZ = function(m,a) {
		this.identity(m);
		m[0] = Math.cos(a);
		m[1] = -Math.sin(a);
		m[4] = Math.sin(a);
		m[5] = Math.cos(a);
	}
	
	this.translate = function(m,x,y,z) {
		this.identity(m);
		m[12] = x;
		m[13] = y;
		m[14] = z;
	}
	
	this.translateV = function(m,v) {
		this.identity(m);
		m[12] = v[0];
		m[13] = v[1];
		m[14] = v[2];
	}
	
	this.getTranslationV = function(m,v) {
		v[0] = m[12];
		v[1] = m[13];
		v[2] = m[14];
	}
	
	this.zero = function(m) {
		m[0] = 0;
		m[1] = 0;
		m[2] = 0;
		m[3] = 0;
		m[4] = 0;
		m[5] = 0;
		m[6] = 0;
		m[7] = 0;
		m[8] = 0;
		m[9] = 0;
		m[10] = 0;
		m[11] = 0;
		m[12] = 0;
		m[13] = 0;
		m[14] = 0;
		m[15] = 0;
	}
	
	this.copy = function(m1,m2) {
		m1[0] = m2[0];
		m1[1] = m2[1];
		m1[2] = m2[2];
		m1[3] = m2[3];
		m1[4] = m2[4];
		m1[5] = m2[5];
		m1[6] = m2[6];
		m1[7] = m2[7];
		m1[8] = m2[8];
		m1[9] = m2[9];
		m1[10] = m2[10];
		m1[11] = m2[11];
		m1[12] = m2[12];
		m1[13] = m2[13];
		m1[14] = m2[14];
		m1[15] = m2[15];
	}
	
	this.identity = function(m) {
		m[0] = 1;
		m[1] = 0;
		m[2] = 0;
		m[3] = 0;
		m[4] = 0;
		m[5] = 1;
		m[6] = 0;
		m[7] = 0;
		m[8] = 0;
		m[9] = 0;
		m[10] = 1;
		m[11] = 0;
		m[12] = 0;
		m[13] = 0;
		m[14] = 0;
		m[15] = 1;
	}
	
	this.add = function(m1,m2) {
		m1[0] += m2[0];
		m1[1] += m2[1];
		m1[2] += m2[2];
		m1[3] += m2[3];
		m1[4] += m2[4];
		m1[5] += m2[5];
		m1[6] += m2[6];
		m1[7] += m2[7];
		m1[8] += m2[8];
		m1[9] += m2[9];
		m1[10] += m2[10];
		m1[11] += m2[11];
		m1[12] += m2[12];
		m1[13] += m2[13];
		m1[14] += m2[14];
		m1[15] += m2[15];
	}
	
	this.sub = function(m1,m2) {
		m1[0] -= m2[0];
		m1[1] -= m2[1];
		m1[2] -= m2[2];
		m1[3] -= m2[3];
		m1[4] -= m2[4];
		m1[5] -= m2[5];
		m1[6] -= m2[6];
		m1[7] -= m2[7];
		m1[8] -= m2[8];
		m1[9] -= m2[9];
		m1[10] -= m2[10];
		m1[11] -= m2[11];
		m1[12] -= m2[12];
		m1[13] -= m2[13];
		m1[14] -= m2[14];
		m1[15] -= m2[15];
	}
	
	this.mulV = function(m,v) {
		this.identity(tempVector);
		tempVector[12] = v[0];
		tempVector[13] = v[1];
		tempVector[14] = v[2];
		this.mul(m,tempVector);
	}
	
	this.mul = function(m1,m2) {
		this.zero(temp);
		temp[0] = m1[0]*m2[0] + m1[1]*m2[4] + m1[2]*m2[8] + m1[3]*m2[12];
		temp[1] = m1[0]*m2[1] + m1[1]*m2[5] + m1[2]*m2[9] + m1[3]*m2[13];
		temp[2] = m1[0]*m2[2] + m1[1]*m2[6] + m1[2]*m2[10] + m1[3]*m2[14];
		temp[3] = m1[0]*m2[3] + m1[1]*m2[7] + m1[2]*m2[11] + m1[3]*m2[15];
		
		temp[4] = m1[4]*m2[0] + m1[5]*m2[4] + m1[6]*m2[8] + m1[7]*m2[12];
		temp[5] = m1[4]*m2[1] + m1[5]*m2[5] + m1[6]*m2[9] + m1[7]*m2[13];
		temp[6] = m1[4]*m2[2] + m1[5]*m2[6] + m1[6]*m2[10] + m1[7]*m2[14];
		temp[7] = m1[4]*m2[3] + m1[5]*m2[7] + m1[6]*m2[11] + m1[7]*m2[15];
		
		temp[8] = m1[8]*m2[0] + m1[9]*m2[4] + m1[10]*m2[8] + m1[11]*m2[12];
		temp[9] = m1[8]*m2[1] + m1[9]*m2[5] + m1[10]*m2[9] + m1[11]*m2[13];
		temp[10] = m1[8]*m2[2] + m1[9]*m2[6] + m1[10]*m2[10] + m1[11]*m2[14];
		temp[11] = m1[8]*m2[3] + m1[9]*m2[7] + m1[10]*m2[11] + m1[11]*m2[15];
		
		temp[12] = m1[12]*m2[0] + m1[13]*m2[4] + m1[14]*m2[8] + m1[15]*m2[12];
		temp[13] = m1[12]*m2[1] + m1[13]*m2[5] + m1[14]*m2[9] + m1[15]*m2[13];
		temp[14] = m1[12]*m2[2] + m1[13]*m2[6] + m1[14]*m2[10] + m1[15]*m2[14];
		temp[15] = m1[12]*m2[3] + m1[13]*m2[7] + m1[14]*m2[11] + m1[15]*m2[15];
		
		m1[0] = temp[0];
		m1[1] = temp[1];
		m1[2] = temp[2];
		m1[3] = temp[3];
		m1[4] = temp[4];
		m1[5] = temp[5];
		m1[6] = temp[6];
		m1[7] = temp[7];
		m1[8] = temp[8];
		m1[9] = temp[9];
		m1[10] = temp[10];
		m1[11] = temp[11];
		m1[12] = temp[12];
		m1[13] = temp[13];
		m1[14] = temp[14];
		m1[15] = temp[15];
	}
	
	this.div = function(m1,m2) {
		this.inverse(m2);
		this.copy(tempVector,temp);
		this.mul(m1,tempVector);
	}
	
	this.projection = function(m,fov,near,far) {
		
	}
	
	this.toConsole = function(m) {
		console.log(m[0],m[1],m[2],m[3]);
		console.log(m[4],m[5],m[6],m[7]);
		console.log(m[8],m[9],m[10],m[11]);
		console.log(m[12],m[13],m[14],m[15]);
	}
	
	this.init();
}

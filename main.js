"use strict";

var canvas = null;
var ctx = null;
var imageWidth = 640;
var imageHeight = 480;
	
var translationMatrix = mat.createMatrix();
var rotationMatrix = mat.createMatrix();
	
var worldViewOrigin = [imageWidth/4,imageHeight/2];
var cameraViewOrigin = [(imageWidth/4) * 3,imageHeight/8];

var viewMatrix = mat.createMatrix();

var tempMatrix = mat.createMatrix(); // "Working" matrix and vector
var tempVector = vec.createVector();

var camera = null;
var fov = 60 * (Math.PI / 180);
var screenDistance = (imageWidth/2) / Math.tan(fov/2);

// Camera space screen dimensions
var cScreenWidth = 2 * screenDistance * Math.tan(fov/2);
var cScreenHeight = 2 * screenDistance * Math.tan(fov/2);

var squareMesh = null;
var squareNode = null;

var up = false;
var down = false;
var left = false;
var right = false;
var mouseDown = false;

var rotationSpeedX = 0.0;
var rotationSpeedY = 0.0;
var stopSpeed = 0.001;
var maxSpeed = 0.1;
var lastX = 0.0;
var lastY = 0.0;

var Model = function(verticies,indicies) {
	this.verticies = verticies;
	this.indexList = indicies;
}

Model.prototype.render = function(worldMatrix) {
	// Vertex shading stage
	var coordinates = [];
	var coord = null;
	
	for (var i = 0; i < this.verticies.length; ++i) {
		mat.translateV(tempMatrix,this.verticies[i]);
		mat.mul(tempMatrix,worldMatrix);
		mat.mul(tempMatrix,viewMatrix);
		mat.getTranslationV(tempMatrix,tempVector);
		
		if (tempVector[2] > 0) {
			coord = [0.0,0.0];
			// NDC Coordinates
			coord[0] = screenDistance * (tempVector[0] / tempVector[2]);
			coord[1] = screenDistance * (tempVector[1] / tempVector[2]);
		
			coord[0] = 2 * coord[0] / cScreenWidth;
			coord[1] = 2 * coord[1] / cScreenHeight;
	
			// Convert to screen Pixels
			coord[0] = (coord[0] + 1) * imageWidth/2;
			coord[1] = (coord[1] + 1) * imageWidth/2;
		
			coordinates.push(coord);
		} else return;
	}
	
	// Pixel shading stage
	
	ctx.strokeStyle = "white";
	ctx.fillStyle = "black";
	ctx.lineWidth = 1;
	ctx.beginPath();
	//ctx.moveTo(coordinates[this.indexList[0]][0],coordinates[this.indexList[0]][1]);
	
	for (var i = 0; i < this.indexList.length; i += 4) {
		ctx.moveTo(coordinates[this.indexList[i]][0],coordinates[this.indexList[i]][1]);
		ctx.lineTo(coordinates[this.indexList[i+1]][0],coordinates[this.indexList[i+1]][1]);
		ctx.lineTo(coordinates[this.indexList[i+2]][0],coordinates[this.indexList[i+2]][1]);
		ctx.lineTo(coordinates[this.indexList[i+3]][0],coordinates[this.indexList[i+3]][1]);
		ctx.lineTo(coordinates[this.indexList[i]][0],coordinates[this.indexList[i]][1]);
	}
	
	ctx.closePath();
	ctx.stroke();
}

var Node = function(x,y,z,angle,model) {
	this.x = x;
	this.y = y;
	this.z = z;
	this.pitch = 0.0; // X Axis
	this.yaw = 0.0; // Y Axis
	this.roll = 0.0; // Z Axis
	this.model = model;
	this.matrix = mat.createMatrix();
	this.updateMatrix();
}

Node.prototype.inverseMatrix = function() {
	mat.identity(this.matrix);
	
	mat.translate(translationMatrix,-this.x,-this.y,-this.z);
	mat.mul(this.matrix,translationMatrix);
	
	mat.rotateZ(rotationMatrix,-this.roll);
	mat.mul(this.matrix,rotationMatrix);
	
	mat.rotateY(rotationMatrix,-this.yaw);
	mat.mul(this.matrix,rotationMatrix);
	
	mat.rotateX(rotationMatrix,-this.pitch);
	mat.mul(this.matrix,rotationMatrix);
	
	//mat.mul(this.matrix,translationMatrix);
	//mat.mul(this.matrix,rotationMatrix);
}
	
Node.prototype.updateMatrix = function() {
	mat.identity(this.matrix);
	
	mat.rotateX(rotationMatrix,this.pitch);
	mat.mul(this.matrix,rotationMatrix);
	
	mat.rotateY(rotationMatrix,this.yaw);
	mat.mul(this.matrix,rotationMatrix);
	
	mat.rotateZ(rotationMatrix,this.roll);
	mat.mul(this.matrix,rotationMatrix);
	
	mat.translate(translationMatrix,this.x,this.y,this.z);
	mat.mul(this.matrix,translationMatrix);
}

Node.prototype.render = function() {
	this.model.render(this.matrix);
}
	
window.onload = function() {
	canvas = document.getElementById("canvas");
	ctx = canvas.getContext("2d");
	canvas.width = imageWidth;
	canvas.height = imageHeight;
	
	camera = new Node(0.0,0.0,0.0,0.0);
	
	squareMesh = new Model([
		vec.createVector([-0.5,0.5,0.5]), // Verticies
		vec.createVector([0.5,0.5,0.5]),
		vec.createVector([-0.5,-0.5,0.5]),
		vec.createVector([0.5,-0.5,0.5]),
		vec.createVector([-0.5,0.5,-0.5]),
		vec.createVector([0.5,0.5,-0.5]),
		vec.createVector([-0.5,-0.5,-0.5]),
		vec.createVector([0.5,-0.5,-0.5])
	],[
		0,1,3,2, // Quad Index List
		4,5,7,6,
		0,4,6,2,
		1,5,7,3
	]);
	
	squareNode = new Node(0.0,-0.25,2.5,0.0,squareMesh);
	
	requestAnimationFrame(loop);
}

window.onkeydown = function(e) {
	switch(e.keyCode) {
		case 38: up = true; break;
		case 87: up = true; break;
		
		case 37: left = true; break;
		case 65: left = true; break;
		
		case 39: right = true; break;
		case 68: right = true; break;
		
		case 83: down = true; break;
		case 40: down = true; break;
	}
}

window.onkeyup = function(e) {
	switch(e.keyCode) {
		case 38: up = false; break;
		case 87: up = false; break;
		
		case 37: left = false; break;
		case 65: left = false; break;
		
		case 39: right = false; break;
		case 68: right = false; break;
		
		case 83: down = false; break;
		case 40: down = false; break;
	}
}

window.onmousedown = function(e) {
	mouseDown = true;
}

window.onmouseup = function(e) {
	mouseDown = false;
}

window.onmousemove = function(e) {
	if (mouseDown) {
		var bounds = canvas.getBoundingClientRect();
		var x = e.clientX - bounds.left;
		var y = e.clientY - bounds.right;
		
		rotationSpeedX = (x - lastX) / 100;
		rotationSpeedY = (y - lastY) / 100;
		
		lastX = x;
		lastY = y;
	}
}
	
var loop = function() {
	// tick
	/*
	if (up) {
		camera.x -= Math.sin(camera.yaw) * 0.1;
		camera.z += Math.cos(camera.yaw) * 0.1;
	}
	
	if (down) {
		camera.x += Math.sin(camera.yaw) * 0.1;
		camera.z -= Math.cos(camera.yaw) * 0.1;
	}
	
	if (left) camera.yaw += 0.02;
	if (right) camera.yaw -= 0.02;
	camera.inverseMatrix();
	mat.copy(viewMatrix,camera.matrix);
	camera.updateMatrix();
	*/
	
	if (rotationSpeedX < 0) {
		if (rotationSpeedX < -maxSpeed) rotationSpeedX = -maxSpeed;
		rotationSpeedX += stopSpeed;
		if (rotationSpeedX > 0) rotationSpeedX = 0.0;
	} else if (rotationSpeedX > 0) {
		if (rotationSpeedX > maxSpeed) rotationSpeedX = maxSpeed;
		rotationSpeedX -= stopSpeed;
		if (rotationSpeedX < 0) rotationSpeedX = 0.0;
	}
	
	if (rotationSpeedY < 0) {
		if (rotationSpeedY < -maxSpeed) rotationSpeedY = -maxSpeed;
		rotationSpeedY += stopSpeed;
		if (rotationSpeedY > 0) rotationSpeedY = 0.0;
	} else if (rotationSpeedY > 0) {
		if (rotationSpeedY > maxSpeed) rotationSpeedY = maxSpeed;
		rotationSpeedY -= stopSpeed;
		if (rotationSpeedY < 0) rotationSpeedY = 0.0;
	}
	
	squareNode.yaw += rotationSpeedX;
	squareNode.pitch += rotationSpeedY;
	squareNode.updateMatrix();
	// render
	ctx.fillStyle = "gray";
	ctx.fillRect(0,0,imageWidth,imageHeight);
	squareNode.render();
	//
	requestAnimationFrame(loop);
}
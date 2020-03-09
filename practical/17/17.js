var canvas = document.getElementById("draw");
var ctx = canvas.getContext("2d");
resize();
function resize() {
  ctx.canvas.width = window.innerWidth;
  ctx.canvas.height = window.innerHeight;
}
window.addEventListener("resize", resize);
document.addEventListener("mousemove", draw);
document.addEventListener("mousedown", setPosition);
document.addEventListener("mouseenter", setPosition);
var pos = { x: 0, y: 0 };
function setPosition(e){
  pos.x = pp.clientX;
  pos.y = pp.clientY;
}
function draw(pp){
  if(pp.buttons !== 1)return;
  var color = document.getElementById("hex").value;
  ctx.beginPath();
  ctx.lineWidth = 20;
  ctx.lineCap = "round";
  ctx.strokeStyle = color;
  ctx.moveTo(pos.x,pos.y);
  setPosition(pp);
  ctx.lineTo(pos.x, pos.y);
  ctx.stroke();
}

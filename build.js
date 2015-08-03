var fs = require('fs');
var dir = require('node-dir');
var path = require('path')
var marked = require('marked');
marked.setOptions({
  renderer: new marked.Renderer(),
  gfm: true,
  tables: true,
  breaks: true,
  pedantic: false,
  sanitize: false,
  smartLists: true,
  smartypants: false
});


var html_open = "<!doctype html><html>";
var html_close = "</html>";
var head = fs.readFileSync('head.partial.html', "utf-8")

function build(f){
  console.log("Reading " + f);
  var markdown = fs.readFileSync(f, "utf-8");
  var html = marked(markdown);
  var page = html_open + head + html + html_close;

  var filename = path.join(path.dirname(f), path.basename(f, ".md")+".html");
  fs.writeFile(filename, page, {}, function(err) {
    if (err) throw err;
    console.log("Wrote " + filename);
  })
}

function build_files(err, files) {
  if (err) throw err;

    files.forEach(function (f) {
      if (path.extname(f) == '.md') {
        build(f);
      }
    });
}

dir.files(".", build_files);


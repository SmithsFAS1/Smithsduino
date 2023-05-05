String formatBytes(size_t bytes) {
  if (bytes < 1024) {
    return String(bytes) + " B";
  } else if (bytes < (1024 * 1024)) {
    return String(bytes / 1024.0) + " KB";
  } else if (bytes < (1024 * 1024 * 1024)) {
    return String(bytes / 1024.0 / 1024.0) + " MB";
  } else {
    return String(bytes / 1024.0 / 1024.0 / 1024.0) + " GB";
  }
}

const char OTAindex[] PROGMEM = R"rawliteral(
  <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>
  <u>Firmware Upload</u><br>
  <form method='POST' action='#' enctype='multipart/form-data' id='upload_form' style='padding:10px;'>
    <input type='file' name='update'>
    <input type='submit' value='Update'>
  </form>
  <div id='prg'>Select file and click "Update"</div>
  <script>
    $('form').submit(function(e){
    e.preventDefault();
    var form = $('#upload_form')[0];
    var data = new FormData(form);
    $.ajax({
      url: '/update',
      type: 'POST',
      data: data,
      contentType: false,
      processData:false,
      xhr: function() {
        var xhr = new window.XMLHttpRequest();
        xhr.upload.addEventListener('progress', function(evt) {
          if (evt.lengthComputable) {
            var per = evt.loaded / evt.total;
            $('#prg').html('progress: ' + Math.round(per*100) + '%');
          }
        }, false);
      return xhr;
      },
        success:function(d, s) {
          $('#prg').html('SUCCESS, RESTARTING');
          setTimeout(function(){window.location.reload();
        }, 5000);
      },
      error: function (a, b, c) {
      }
    });
  });
  </script>
   )rawliteral";

const char logoutHTML[] PROGMEM = R"rawliteral(
  <script>
  function logoutButton() {
    if (confirm("Log out?") == true) {
      var xhr = new XMLHttpRequest();
      xhr.open('GET',window.location.protocol + '//log:out@' + window.location.hostname + '/logout', true);
      xhr.send();
      setTimeout(function(){ window.open('/logged-out','_self'); }, 1000);
    }
  }
  </script>
  <div><button onclick="logoutButton();">Logout</button></div>
  )rawliteral";

const char logout_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
  <p>Logged out or <a href="/">return to homepage</a>.</p>
  <p><strong>Note:</strong> close all web browser tabs to complete the logout process.</p>
</body>
</html>
)rawliteral";

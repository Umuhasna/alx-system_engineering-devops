# Install nginx using puppet
package { 'nginx':
  ensure => installed,
}

file { '/var/www/html/index.nginx-debian.html':
  content => 'Hello World!',
}

file_line { 'append_redirect_me':
  path  => '/etc/nginx/sites-available/default',
  after => 'server_name_;',
  line  => '\n\tlocation /redirect_me {\n\t\treturn 301 https://youtu.be/dQw4w9WgXcQ;\n\t}\n',
}

service { 'nginx':
  ensure => running,
}

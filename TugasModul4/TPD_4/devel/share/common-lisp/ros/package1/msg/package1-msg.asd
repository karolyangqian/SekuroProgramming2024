
(cl:in-package :asdf)

(defsystem "package1-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "pesan" :depends-on ("_package_pesan"))
    (:file "_package_pesan" :depends-on ("_package"))
  ))
;; Auto-generated. Do not edit!


(when (boundp 'package1::magnitude)
  (if (not (find-package "PACKAGE1"))
    (make-package "PACKAGE1"))
  (shadow 'magnitude (find-package "PACKAGE1")))
(unless (find-package "PACKAGE1::MAGNITUDE")
  (make-package "PACKAGE1::MAGNITUDE"))
(unless (find-package "PACKAGE1::MAGNITUDEREQUEST")
  (make-package "PACKAGE1::MAGNITUDEREQUEST"))
(unless (find-package "PACKAGE1::MAGNITUDERESPONSE")
  (make-package "PACKAGE1::MAGNITUDERESPONSE"))

(in-package "ROS")





(defclass package1::magnitudeRequest
  :super ros::object
  :slots (_komponenX _komponenY _komponenZ ))

(defmethod package1::magnitudeRequest
  (:init
   (&key
    ((:komponenX __komponenX) 0.0)
    ((:komponenY __komponenY) 0.0)
    ((:komponenZ __komponenZ) 0.0)
    )
   (send-super :init)
   (setq _komponenX (float __komponenX))
   (setq _komponenY (float __komponenY))
   (setq _komponenZ (float __komponenZ))
   self)
  (:komponenX
   (&optional __komponenX)
   (if __komponenX (setq _komponenX __komponenX)) _komponenX)
  (:komponenY
   (&optional __komponenY)
   (if __komponenY (setq _komponenY __komponenY)) _komponenY)
  (:komponenZ
   (&optional __komponenZ)
   (if __komponenZ (setq _komponenZ __komponenZ)) _komponenZ)
  (:serialization-length
   ()
   (+
    ;; float64 _komponenX
    8
    ;; float64 _komponenY
    8
    ;; float64 _komponenZ
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _komponenX
       (sys::poke _komponenX (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _komponenY
       (sys::poke _komponenY (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _komponenZ
       (sys::poke _komponenZ (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _komponenX
     (setq _komponenX (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _komponenY
     (setq _komponenY (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _komponenZ
     (setq _komponenZ (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass package1::magnitudeResponse
  :super ros::object
  :slots (_magnitude ))

(defmethod package1::magnitudeResponse
  (:init
   (&key
    ((:magnitude __magnitude) 0.0)
    )
   (send-super :init)
   (setq _magnitude (float __magnitude))
   self)
  (:magnitude
   (&optional __magnitude)
   (if __magnitude (setq _magnitude __magnitude)) _magnitude)
  (:serialization-length
   ()
   (+
    ;; float64 _magnitude
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _magnitude
       (sys::poke _magnitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _magnitude
     (setq _magnitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass package1::magnitude
  :super ros::object
  :slots ())

(setf (get package1::magnitude :md5sum-) "55d1a215f43fd1f64eb105a505b172c4")
(setf (get package1::magnitude :datatype-) "package1/magnitude")
(setf (get package1::magnitude :request) package1::magnitudeRequest)
(setf (get package1::magnitude :response) package1::magnitudeResponse)

(defmethod package1::magnitudeRequest
  (:response () (instance package1::magnitudeResponse :init)))

(setf (get package1::magnitudeRequest :md5sum-) "55d1a215f43fd1f64eb105a505b172c4")
(setf (get package1::magnitudeRequest :datatype-) "package1/magnitudeRequest")
(setf (get package1::magnitudeRequest :definition-)
      "float64 komponenX
float64 komponenY
float64 komponenZ
---
float64 magnitude
")

(setf (get package1::magnitudeResponse :md5sum-) "55d1a215f43fd1f64eb105a505b172c4")
(setf (get package1::magnitudeResponse :datatype-) "package1/magnitudeResponse")
(setf (get package1::magnitudeResponse :definition-)
      "float64 komponenX
float64 komponenY
float64 komponenZ
---
float64 magnitude
")



(provide :package1/magnitude "55d1a215f43fd1f64eb105a505b172c4")



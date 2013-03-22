/*
 * MediaSet.hpp - Kurento Media Server
 *
 * Copyright (C) 2013 Kurento
 * Contact: Miguel París Díaz <mparisdiaz@gmail.com>
 * Contact: José Antonio Santos Cadenas <santoscadenas@kurento.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __MEDIA_SET_H__
#define __MEDIA_SET_H__

#include "ConcurrentMap.hpp"
#include "types/MediaFactory.hpp"
#include "types/MediaPlayer.hpp"
#include "types/MediaRecorder.hpp"

namespace kurento
{

class MediaSet
{
public:
  MediaSet () {};

  void put (MediaObject *mediaObject);
  int size();
  MediaFactory *getMediaFactory (const MediaObject &mediaObject);
  Joinable *getJoinable (const MediaObject &mediaObject);
  MediaPlayer *getMediaPlayer (const MediaObject &mediaObject);
  MediaRecorder *getMediaRecorder (const MediaObject &mediaObject);

private:
  ConcurrentMap<ObjectId, MediaObject *> mediaObjectMap;
};

} // kurento

#endif /* __MEDIA_SET_H__ */

/*
 * Copyright (c) 2019, Red Hat, Inc. All rights reserved.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#include "precompiled.hpp"
#include "gc_implementation/shenandoah/shenandoahHeap.inline.hpp"
#include "gc_implementation/shenandoah/shenandoahOopClosures.hpp"
#include "runtime/thread.hpp"

ShenandoahTraversalSuperClosure::ShenandoahTraversalSuperClosure(ShenandoahObjToScanQueue* q, ReferenceProcessor* rp, ShenandoahStrDedupQueue* dq) :
  MetadataAwareOopClosure(rp),
  _traversal_gc(ShenandoahHeap::heap()->traversal_gc()),
  _dedup_queue(dq),
  _thread(Thread::current()),
  _queue(q),
  _mark_context(ShenandoahHeap::heap()->marking_context()) {
}
